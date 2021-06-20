add_library(TL STATIC
	base/tl_system.h
	base/tl_system.cpp
	base/tl_defs.h
	base/tl_thread.h
	jobqueue/jobqueue.h
	jobqueue/jobqueue_atomic_heap.h
	jobqueue/jobqueue_atomic_queue_lf.h
	)