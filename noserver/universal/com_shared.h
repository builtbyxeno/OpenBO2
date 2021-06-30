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

#ifndef COM_SHARED_H
#define COM_SHARED_H

bool Com_Filter(char const*, char const*, int);
bool Com_FilterPath(char const*, char const*, int);
int Com_HashKey(char const*, int);
void Com_GetQTime(int, struct qtime_s*, bool);
int Com_RealTime(struct qtime_s*, bool);
void Com_Memset(void*, int, int);

#endif