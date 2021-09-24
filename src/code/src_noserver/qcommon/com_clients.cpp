#include "types.h"
#include "vars.h"
#include <client/client.h>
#include <win32/win32_public.h>
#include <cgame/cgame_public.h>

ClientGameState clientGameStates[1];
LocalClientNum_t primaryLocalClient = INVALID_LOCAL_CLIENT;
int resetTime;

/*
==============
Com_LocalClients_AssignUIContextsForInGame
==============
*/
void Com_LocalClients_AssignUIContextsForInGame()
{
	int cgsIndex;
	int contextIndex;

	contextIndex = 0;
	cgsIndex = 0;
	while (cgsIndex < 1)
	{
		clientGameStates[cgsIndex].uiContextIndex = (UIContextIndex_t)contextIndex;
		cgsIndex++;
		contextIndex++;
	}
}

/*
==============
Com_LocalClient_GetUIContextIndex
==============
*/
UIContextIndex_t Com_LocalClient_GetUIContextIndex(LocalClientNum_t localClientNum)
{
	int cgsIndex;

	assertIn(localClientNum, MAX_LOCAL_CLIENTS);
	for (cgsIndex = 0; cgsIndex < 1; ++cgsIndex)
	{
		if (clientGameStates[cgsIndex].localClientNum == localClientNum)
		{
			return clientGameStates[cgsIndex].uiContextIndex;
		}
	}

	assert(0);
	return INVALID_UI_CONTEXT;
}

/*
==============
Com_LocalClient_GetControllerIndex
==============
*/
ControllerIndex_t Com_LocalClient_GetControllerIndex(LocalClientNum_t localClientNum)
{
	int cgsIndex;

	assertIn(localClientNum, MAX_LOCAL_CLIENTS);
	for (cgsIndex = 0; cgsIndex < 1; ++cgsIndex)
	{
		if (clientGameStates[cgsIndex].localClientNum == localClientNum)
		{
			return clientGameStates[cgsIndex].controllerIndex;
		}
	}

	assert(0);
	return (ControllerIndex_t)-1;
}

/*
==============
Com_LocalClient_GetNetworkID
==============
*/
netsrc_t Com_LocalClient_GetNetworkID(LocalClientNum_t localClientNum)
{
	int cgsIndex;

	assertIn(localClientNum, MAX_LOCAL_CLIENTS);
	for (cgsIndex = 0; cgsIndex < 1; ++cgsIndex)
	{
		if (clientGameStates[cgsIndex].localClientNum == localClientNum)
		{
			return clientGameStates[cgsIndex].networkID;
		}
	}

	assert(0);
	return NS_PACKET;
}

/*
==============
Com_LocalClient_SetControllerIndex
==============
*/
void Com_LocalClient_SetControllerIndex(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex)
{
	assertIn(localClientNum, MAX_LOCAL_CLIENTS);
	clientGameStates[localClientNum].controllerIndex = controllerIndex;
}

/*
==============
Com_LocalClient_SetPrimary
==============
*/
void Com_LocalClient_SetPrimary(LocalClientNum_t localClientNum, bool primary)
{
	if (primary)
	{
		primaryLocalClient = localClientNum;
	}
	else if (primaryLocalClient == localClientNum)
	{
		primaryLocalClient = INVALID_LOCAL_CLIENT;
	}
}

/*
==============
Com_LocalClients_GetPrimary
==============
*/
LocalClientNum_t Com_LocalClients_GetPrimary()
{
	return primaryLocalClient;
}

/*
==============
Com_LocalClients_GetPrimaryDefault
==============
*/
LocalClientNum_t Com_LocalClients_GetPrimaryDefault()
{
	return (LocalClientNum_t)(primaryLocalClient != INVALID_LOCAL_CLIENT ? primaryLocalClient : 0);
}

/*
==============
Com_LocalClient_IsPrimary
==============
*/
bool Com_LocalClient_IsPrimary(LocalClientNum_t localClientNum)
{
	return primaryLocalClient == localClientNum;
}

/*
==============
Com_LocalClient_IsPrimarySet
==============
*/
BOOL Com_LocalClient_IsPrimarySet()
{
	return primaryLocalClient != INVALID_LOCAL_CLIENT;
}

/*
==============
Com_LocalClient_IsBeingUsed
==============
*/
bool Com_LocalClient_IsBeingUsed(LocalClientNum_t localClientNum)
{
	assertIn(localClientNum, MAX_LOCAL_CLIENTS);
	return (clientGameStates[localClientNum].flags & 1) != 0;
}

/*
==============
Com_LocalClient_SetBeingUsed
==============
*/
void Com_LocalClient_SetBeingUsed(LocalClientNum_t localClientNum, bool beingUsed)
{
	assertIn(localClientNum, MAX_LOCAL_CLIENTS);
	if (beingUsed)
	{
		clientGameStates[localClientNum].flags |= 1;
	}
	else
	{
		clientGameStates[localClientNum].flags &= ~1;
	}
}

/*
==============
Com_LocalClients_NoneBeingUsed
==============
*/
bool Com_LocalClients_NoneBeingUsed()
{
	int clients = 0;
	while (true)
	{
		if (clients != -1)
			if ((clientGameStates[clients].flags & 1) != 0)
				break;
		if (++clients >= 1)
			return true;
	}
	return false;
}

/*
==============
Com_LocalClients_GetUsedControllerCount
==============
*/
int Com_LocalClients_GetUsedControllerCount()
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 1)
	{
		if (Com_LocalClient_IsBeingUsed((LocalClientNum_t)i))
		{
			++count;
		}
		++i;
	}
	return count;
}

/*
==============
Com_ControllerIndex_GetLocalClientNum
==============
*/
LocalClientNum_t Com_ControllerIndex_GetLocalClientNum(ControllerIndex_t controllerIndex)
{
	int cgsIndex;

	assertIn(controllerIndex, MAX_GPAD_COUNT);
	for (cgsIndex = 0; cgsIndex < 1; ++cgsIndex)
	{
		if (clientGameStates[cgsIndex].controllerIndex == controllerIndex)
		{
			return clientGameStates[cgsIndex].localClientNum;
		}
	}

	assert(0);
	return (LocalClientNum_t )-1;
}

/*
==============
Com_ControllerIndex_GetNetworkID
==============
*/
netsrc_t Com_ControllerIndex_GetNetworkID(ControllerIndex_t controllerIndex)
{
	int cgsIndex;

	for (cgsIndex = 0; cgsIndex < 1; ++cgsIndex)
	{
		if (clientGameStates[cgsIndex].controllerIndex == controllerIndex)
			return clientGameStates[cgsIndex].networkID;
	}
}

/*
==============
Com_ControllerIndex_GetUIContextIndex
==============
*/
UIContextIndex_t Com_ControllerIndex_GetUIContextIndex(ControllerIndex_t controllerIndex)
{
	int cgsIndex;

	assertIn(controllerIndex, MAX_GPAD_COUNT);
	for (cgsIndex = 0; cgsIndex < 1; ++cgsIndex)
	{
		if (clientGameStates[cgsIndex].controllerIndex == controllerIndex)
		{
			return clientGameStates[cgsIndex].uiContextIndex;
		}
	}
	assert(0);
	return (UIContextIndex_t )-1;
}

/*
==============
Com_ControllerIndexes_GetPrimary
==============
*/
ControllerIndex_t Com_ControllerIndexes_GetPrimary()
{
	if (!DEDICATED)
	{
		for (int i = 0; i < 1; ++i)
		{
			if (Com_LocalClient_IsPrimary((LocalClientNum_t)i))
			{
				return Com_LocalClient_GetControllerIndex((LocalClientNum_t)i);
			}
		}

		assertMsg("Someone asked for the primary client controller and it was not set\n");
	}

	return (ControllerIndex_t)0;
}

/*
==============
Com_NetworkID_GetControllerIndex
==============
*/
ControllerIndex_t Com_NetworkID_GetControllerIndex(netsrc_t netID)
{
	int cgsIndex;

	if (netID == NS_SERVER)
	{
		return Com_LocalClient_GetControllerIndex(primaryLocalClient);
	}
	for (cgsIndex = 0; cgsIndex < 1; ++cgsIndex)
	{
		if (clientGameStates[cgsIndex].networkID == netID)
		{
			return clientGameStates[cgsIndex].controllerIndex;
		}
	}
	return INVALID_CONTROLLER_PORT;
}

/*
==============
Com_LocalClient_LastInput_Set
==============
*/
void Com_LocalClient_LastInput_Set(LocalClientNum_t localClientNum, LastInput_t currentInput)
{
	LastInput_t lastInput;
	if (clientGameStates[localClientNum].lastInput == currentInput)
		resetTime = 0;
	else
	{
		if (resetTime && resetTime <= Sys_Milliseconds())
		{
			lastInput = clientGameStates[localClientNum].lastInput;
			resetTime = 0;
			clientGameStates[localClientNum].lastInput = currentInput;
			if (lastInput == LAST_INPUT_GAMEPAD || currentInput == LAST_INPUT_GAMEPAD)
				CG_UpdateVehicleBindings(localClientNum);
		}
	}
}

/*
==============
Com_LocalClient_LastInput_Get
==============
*/
LastInput_t Com_LocalClient_LastInput_Get(LocalClientNum_t localClientNum)
{
	return clientGameStates[localClientNum].lastInput;
}

/*
==============
Com_InitClientGameStates
==============
*/
void Com_InitClientGameStates()
{
	clientGameStates[0].networkID = NS_CLIENT1;
	clientGameStates[0].flags = 0;
	clientGameStates[0].controllerIndex = CONTROLLER_INDEX_0;
	if (resetTime && resetTime <= Sys_Milliseconds())
	{
		LastInput_t lastInput = clientGameStates[0].lastInput;
		resetTime = 0;
		clientGameStates[0].lastInput = LAST_INPUT_KEYBOARD;
		if (lastInput == LAST_INPUT_GAMEPAD)
			CG_UpdateVehicleBindings(LOCAL_CLIENT_FIRST);
	}
}

/*
==============
SwapClients
==============
*/
void SwapClients(int clientA, int clientB)
{
	ClientGameState clientGamestateTemp;
	clientUIActive_t uiActiveTemp;
	clientConnection_t* clientConnectionTemp;
	LargeLocal clientConnectionTemp_large_local(sizeof(clientConnection_t));

	clientConnectionTemp = (clientConnection_t*)clientConnectionTemp_large_local.GetBuf();
	uiActiveTemp = clientUIActives[clientA];
	clientUIActives[clientA] = clientUIActives[clientB];
	clientUIActives[clientB] = uiActiveTemp;

	clientGamestateTemp = clientGameStates[clientA];
	clientGameStates[clientA] = clientGameStates[clientB];
	clientGameStates[clientB] = clientGamestateTemp;

	clientGameStates[clientA].localClientNum = (LocalClientNum_t)clientA;
	clientGameStates[clientB].localClientNum = (LocalClientNum_t)clientB;

	if (clientConnections)
	{
		memcpy(clientConnectionTemp, &clientConnections[clientA], sizeof(clientConnection_t));
		memcpy(&clientConnections[clientA], &clientConnections[clientB], sizeof(clientConnection_t));
		memcpy(&clientConnections[clientB], clientConnectionTemp, sizeof(clientConnection_t));
	}
}

/*
==============
Com_LocalClients_CompressClients
==============
*/
void Com_LocalClients_CompressClients()
{
	int testIndex;
	int swapIndex;
	int localClientNum;
	int activeIndex;
	int cgsIndex;
	int lastUsedIndex;

	lastUsedIndex = 0;
	for (cgsIndex = 0; cgsIndex < 1; ++cgsIndex)
	{
		if (Com_LocalClient_IsBeingUsed((LocalClientNum_t)cgsIndex))
		{
			lastUsedIndex = cgsIndex;
		}
		else
		{
			for (activeIndex = cgsIndex + 1; activeIndex < 1; ++activeIndex)
			{
				if (Com_LocalClient_IsBeingUsed((LocalClientNum_t)activeIndex))
				{
					SwapClients(cgsIndex, activeIndex);
					lastUsedIndex = cgsIndex;
					break;
				}
			}
		}
	}
	for (localClientNum = 0; localClientNum <= lastUsedIndex; ++localClientNum)
	{
		assert(Com_LocalClient_IsBeingUsed((LocalClientNum_t)cgsIndex));
		swapIndex = localClientNum;
		for (testIndex = localClientNum + 1; testIndex <= lastUsedIndex; ++testIndex)
		{
			if (clientGameStates[localClientNum].controllerIndex > clientGameStates[testIndex].controllerIndex)
			{
				swapIndex = testIndex;
			}
		}
		if (swapIndex != localClientNum)
		{
			SwapClients(localClientNum, swapIndex);
		}
	}
}

