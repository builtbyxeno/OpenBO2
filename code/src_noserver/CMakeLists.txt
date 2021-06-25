include_directories(.)

add_executable(noserver WIN32
	"qcommon/mem_track.cpp"
	"universal/q_shared.cpp" 
	"universal/com_vector.h" 
	"universal/com_math_anglevectors.h" 
	"universal/com_math_anglevectors.cpp" 
	"qcommon/threads.h" 
	"qcommon/threads.cpp"
	"gfx_d3d/r_pix_profile.h"
	"universal/com_math.h"
	"universal/com_math.cpp"
	"universal/com_vector.cpp" "universal/dvar.h" "universal/dvar.cpp" "universal/com_memory.h" "qcommon/threads_interlock.h")