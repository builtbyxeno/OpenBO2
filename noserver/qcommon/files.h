/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FILES_H
#define FILES_H

void TRACK_files(void);
int FS_SV_FOpenFileWrite(char const*, char const*);
int FS_SV_FOpenFileRead(char const*, char const*, int*);
int FS_GetModList(char*, int);
void FS_Dir_f(void);
void FS_NewDir_f(void);
void FS_TouchFile_f(void);
int FS_iwIwd(char const*, char*);
void FS_RemoveCommands(void);
void FS_AddCommands(void);
void FS_SetRestrictions(void);
void FS_LoadedIwds(char const**, char const**);
char const* FS_LoadedIwdPureChecksums(void);
void FS_ReferencedIwds(char const**, char const**);
char const* FS_ReferencedIwdPureChecksums(void);
bool FS_PureServerSetLoadedIwds(char const*, char const*);
int FS_ServerSetReferencedFiles(char const*, char const*, int, int*, char const**);
void FS_ServerSetReferencedIwds(char const*, char const*);
void FS_ServerSetReferencedFFs(char const*, char const*);
char const* FS_GetMapBaseName(char const*);

#endif