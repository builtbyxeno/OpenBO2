#include "types.h"

/*
==============
CCS_ClearConstantConfigStrings
==============
*/
void CCS_ClearConstantConfigStrings()
{
	configStringTable = 0;
	configStringTableChecksum = 0;
	Com_DPrintf(11, "CCS: Cleared\n");
}

/*
==============
CCS_ValidateChecksums
==============
*/
void CCS_ValidateChecksums(int serverChecksum, int clientChecksum)
{
	if (serverChecksum)
	{
		if (clientChecksum)
		{
			if (serverChecksum != clientChecksum)
			{
				Com_PrintError(
					25,
					"Our config string checksum %i doesn't match the server's checksum %i\n",
					clientChecksum,
					serverChecksum);
				Com_Error(ERR_DROP, "EXE_CONFIGSTRINGMISMATCH");
			}
		}

		else
		{
			const char* systemlink = "on";

			if (!Com_SessionMode_IsMode(SESSIONMODE_SYSTEMLINK))
				systemlink = "off";

			const char* onlinegame = "on";

			if (!Com_SessionMode_IsOnlineGame())
				onlinegame = "off";

			Com_PrintError(
				25,
				"The server sent us a config checksum (%i) but we have don't have one, (onlinegame is %s)(systemlink is %s)\n",
				serverChecksum,
				onlinegame,
				systemlink);
			Com_Error(ERR_DROP, "EXE_CONFIGSTRINGMISMATCH3");
		}
	}

	else if (clientChecksum)
	{
		const char* systemlink = "on";

		if (!Com_SessionMode_IsMode(SESSIONMODE_SYSTEMLINK))
			systemlink = "off";

		const char* onlinegame = "on";

		if (!Com_SessionMode_IsOnlineGame())
			onlinegame = "off";

		Com_PrintError(
			25,
			"The server did not send us a config checksum but we have one (%i), (onlinegame is %s)(systemlink is %s)\n",
			clientChecksum,
			onlinegame,
			systemlink);
		Com_Error(ERR_DROP, "EXE_CONFIGSTRINGMISMATCH2");
	}
}

/*
==============
CCS_GetChecksum
==============
*/
int CCS_GetChecksum()
{
	Com_DPrintf(11, "CCS: CCS_GetChecksum: %d\n", configStringTableChecksum);
	return configStringTableChecksum;
}

/*
==============
CCS_LoadConstantConfigStrings
==============
*/
void CCS_LoadConstantConfigStrings(const char *mapname, const char *gametype)
{
	assert(mapname);
	assert(gametype);
	assert(mapname[0]);
	assert(gametype[0]);

	Com_sprintf(filename, 256, "%s/configStrings/configStrings_%s.csv", "mp", mapname);
	StringTable_GetAsset();
	configStringTableChecksum = StringTable_Checksum(configStringTable, 0);
	Com_DPrintf(11, "CCS: CCS_LoadConstantConfigStrings %s: %d\n", filename, configStringTableChecksum);
}

/*
==============
CCS_GetConfigStringValue
==============
*/
const char *CCS_GetConfigStringValue(const int rowNum)
{
	if (configStringTable)
		return StringTable_GetColumnValueForRow(configStringTable, rowNum, 0);
	else
		return "";
}

/*
==============
CCS_FindConfigStringRow
==============
*/
int CCS_FindConfigStringRow(const char *value, const int previousRow)
{
	assert(previousRow >= 0);

	if (!configStringTable)
		return -1;

	const int result = StringTable_LookupNearestRowNumForValue(configStringTable, 0, value, previousRow);

	if (result < previousRow)
		return -1;

	return result;
}

