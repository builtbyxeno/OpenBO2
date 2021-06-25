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

#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include "jobqueue_atomic_queue_lf.h"

enum jqWorkerType : __int32
{
	JQ_WORKER_GENERIC = 0x0,
	JQ_WORKER_MAX = 0x1,
	JQ_WORKER_DEFAULT = 0x0,
};

typedef class jqBatchGroup {
	union {
		struct {
			int QueuedBatchCount;
			int ExecutingBatchCount;
		};
		unsigned __int64 BatchCount;
	};
};

typedef class jqModule;

typedef class jqBatch {
	void* p3x_info;
	void* Input;
	void* Output;
	jqModule* Module;
	jqBatchGroup* GroupID;
	void* ConditionalAddress;
	unsigned int ConditionalValue;
	unsigned int ParamData[55];
	//_jqBatch _Batch;
};

typedef class jqModule {
	const char* Name;
	jqWorkerType Type;
	int(__cdecl* Code)(jqBatch*);
	jqBatchGroup Group;
	unsigned __int64 Ticks;
	unsigned __int16 Calls;
	unsigned __int16 Requeues;
};

typedef class jqQueue {
	jqQueue* ThisPtr;
	jqAtomicQueue<jqBatch, 32> Queue;
	int QueuedBatchCount;
	unsigned int ProcessorsMask;
};

typedef class jqConditionalQueue {
	jqQueue Queue;
	jqQueue* DstQueue;
	unsigned int allow;
	int lock;
};

#endif