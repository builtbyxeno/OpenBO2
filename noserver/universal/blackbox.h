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

#ifndef BLACKBOX_H
#define BLACKBOX_H

int BB_FindThrottledType(unsigned int, int*);
bool BB_CheckThrottle(char const*);
void BB_SetThrottle(char const*, int);
void BB_Print(enum ControllerIndex_t, char const*, char const*, ...);
void GScr_BBPrint(void);
void BB_WriteInstanceData(enum ControllerIndex_t);
int BB_RegisterHighWaterMark(char const*);
void BB_SetHighWaterMark(int, unsigned int);
void BB_SetupMsg(void);
void BB_Enable_f(void);
void BB_Disable_f(void);
void BB_Throttle_f(void);
void BB_Start(void);
void BB_Start_f(void);
void BB_Send(enum ControllerIndex_t, bool, bool);
void BB_Alert(char const*, int, char const*, char const*);
void BB_Notify(bool, char const*, char const*, bool);
void BB_ResetHighWaterMarks(void);
void BB_ResetHighWaterMark(char const*);
void BB_Send_f(void);
void BB_Init(void);

#endif